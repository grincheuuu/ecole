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
namee = " = "
commentt = " = "
for i in range(len(arg)):
    if "name" in arg[i]:
        namee = arg[i]
    if "comment" in arg[i]:
        commentt = arg[i]
        break

name = namee.split("=")[1] if "=" in namee else "inconnu"
comment = commentt.split("=")[1] if "=" in commentt else "vide"

# print("Content-Type: text/plain\n")  # En-tête HTTP
# print("Données reçues:")
# print(post_data)  # Afficher les données reçues

print("HTTP/1.1 200 OK")
print ("Content-type:text/html; charset=UTF-8")
print ()
a = f"""
<!DOCTYPE html>
    <html>
    <head><title>Hello word</title></head>
    <body>
        <p>Hello {name} </p>
        <p>1er CGI</p>
        <p>{comment}</p>
    </body>
    </html>
"""
print(a)