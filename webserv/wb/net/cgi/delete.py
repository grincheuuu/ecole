#!/usr/bin/python3
import os
import sys
import cgi
 
# Lire la taille du body depuis l'en-tête Content-Length
pwd = os.getcwd()
UPLOAD_DIR = pwd + "/net/picture"

form = cgi.FieldStorage()
filename = form.getvalue("filename")

if not filename:
    print("HTTP/1.1 400 Bad Request")
    print ("Content-type:text/html; charset=UTF-8")
    print ()
    a = f"""
    <!DOCTYPE html>
        <html>
        <head><title>SUPPRESSSION</title></head>
        <body>
            <p>file not found</p>
        </body>
        </html>
    """
    print(a)
else:
    filepath = os.path.join(UPLOAD_DIR, filename)
    if os.path.exists(filepath):
        os.remove(filepath)
        print("HTTP/1.1 200 OK")
        print ("Content-type:text/html; charset=UTF-8")
        print ()
        a = f"""
        <!DOCTYPE html>
            <html>
            <head><title>SUPPRESSSION</title></head>
            <body>
                <p>THIS FILE : {filename} WILL BE SUPPRESSED</p>
                <p>????????????</p>
                <p>its OK</p>
            </body>
            </html>
        """
        print(a)
    else:
        print("HTTP/1.1 404 Not Found")
        print ("Content-type:text/html; charset=UTF-8")
        print ()
        a = f"""
        <!DOCTYPE html>
            <html>
            <head><title>SUPPRESSSION</title></head>
            <body>
                <p>THIS FILE : {filename} WILL BE SUPPRESSED</p>
                <p>????????????</p>
                <p>echec suppression</p>
                <p>file not found</p>
            </body>
            </html>
        """
        print(a)

