#!/usr/bin/python3
import os
import sys
 
# Lire la taille du body depuis l'en-tête Content-Length
content_length = os.environ.get("CONTENT_LENGTH")
try:
    content_length = int(content_length)
    if content_length > 0:
        post_data = sys.stdin.read(content_length)  # Lire exactement le nombre d'octets attendu
    else:
        post_data = os.getenv("QUERY_STRING")
except ValueError:
    post_data = os.getenv("QUERY_STRING")

arg = post_data.split("&")
secrete = " = "
emaill = " = "
for i in range(len(arg)):
    if "secret" in arg[i]:
        secrete = arg[i]
    if "email" in arg[i]:
        emaill = arg[i]

email = emaill.split("=")[1] if "=" in emaill else "unknown"
secret = secrete.split("=")[1] if "=" in secrete else "no"

#  print("Content-Type: text/plain\n")  # En-tête HTTP
#  print("Données reçues:")
#  print(post_data)  # Afficher les données reçues

print("HTTP/1.1 200 OK")
print ("Content-type:text/html; charset=UTF-8")
print ()
a = f"""
<!DOCTYPE html>
    <html>
    <head><title>GOOD MORNING</title></head>
    <body>
        <p>your email is ? {email} or something else</p>
        <p>????????????</p>
        <p>your secret is {secret}</p>
        <p>don't tell</p>
        <p>don't show</p>
        <p>to everyone</p>
    </body>
    </html>
"""
print(a)