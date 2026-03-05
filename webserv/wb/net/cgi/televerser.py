#!/usr/bin/python3
import os
import sys
import re

# 📂 Répertoire où stocker l'image
pwd = os.getcwd()
UPLOAD_DIR = pwd + "/net/picture"

# 📏 Lire la taille des données envoyées
try:
    content_length = int(os.environ.get("CONTENT_LENGTH", "0"))
except ValueError:
    content_length = 0

if content_length <= 0:
    print("HTTP/1.1 500 Internal Server Error")
    print ("Content-type:text/html; charset=UTF-8")
    print ()
    print("<html><body><p>Erreur: Aucun fichier reçu.</p></body></html>")
    sys.exit(1)

# 📥 Lire les données de STDIN
data = sys.stdin.buffer.read(content_length)
with open("dataDump", "wb") as f:
    f.write(data)

# 🔍 Détection du boundary
boundary = re.search(rb"^--(.+)", data)
if not boundary:
    print("HTTP/1.1 500 Internal Server Error")
    print ("Content-type:text/html; charset=UTF-8")
    print ()
    print("<html><body><p>Erreur: Boundary introuvable.</p></body></html>")
    sys.exit(1)

boundary = boundary.group(1)

# 🧐 Extraire les fichiers envoyés
parts = data.split(b"--" + boundary)
#print(data)
#print()
for part in parts:
    if b"Content-Disposition" in part and b"filename=" in part:
        # 📌 Extraire le nom du fichier
        filename_match = re.search(rb'filename="([^"]+)"', part)
        if not filename_match:
            continue
        filename = filename_match.group(1).decode()
        filename = os.path.basename(filename)  # Éviter les problèmes de sécurité

        # 📌 Trouver le début des données du fichier
        file_data_start = part.find(b"\r\n\r\n") + 4
#        print(file_data_start)
        file_data = part[file_data_start:].rstrip(b"\n--")  # Enlever les boundary finaux
#        print(file_data)

        # 📥 Écriture dans le fichier
        filepath = os.path.join(UPLOAD_DIR, filename)
        ff = "/net/picture/" + filename
        file_data = file_data.split(b"\r\n--")[0]
#        print()
#        print(file_data)
        try:
            with open(filepath, "wb") as f:
                f.write(file_data)
        except Exception as e:
            print("HTTP/1.1 500 Internal Server Error")
            print ("Content-type:text/html; charset=UTF-8")
            print ()
            print("<html><body><p>Erreur lors de l'enregistrement du fichier</p></body></html>")
            sys.exit(1)

        # ✅ Réponse de succès
        print("HTTP/1.1 200 OK")
        print ("Content-type:text/html; charset=UTF-8")
        print ()
        print("<html><body>")
        print(f"<p>Fichier <strong>{filename}</strong> televerse avec succes!</p>")
        print(f"<p>Stocke dans : {filepath} {ff}</p>")
        print("</body></html>")
        sys.exit(0)

# ⚠️ Aucune donnée valide trouvée
print("HTTP/1.1 500 Internal Server Error")
print ("Content-type:text/html; charset=UTF-8")
print ()
print("<html><body><p>Erreur: Aucun fichier valide trouve.</p></body></html>")
sys.exit(1)
