print("hello world")
print((100 + 80)*11)
livre = "gatsby le magnifique"
hello = 'salut'
temps_ensoleille = True
age = 30
print(f"hello wolrd livre = {livre} age {age}")
print(type(livre))
print(type(hello))
print(type(temps_ensoleille))
print(type(age))
liste = ["facebook", "instagram", "snapchat"]
liste2 = ["facebook", 2]
print(liste2[0])
print(type(liste2[0]))
print(liste2[1])
print(type(liste2[1]))
print(liste[-1])
print(liste[-2])
liste[1] = "chatgpt"
print(liste)
#ajouter, retirer, trier les listes
# methode de liste
#append() ajouter une element a la fin de a liste
liste.append("msn")
print(liste)
#retirer un element specifique mais que le 1er ou dernier element de la liste
liste.remove("facebook")
print(liste)
print(len(liste))
#len() fonction sur les listes, les strings, ...
liste.sort()
liste3 = [4, 5 , 2, 8, 3, 9]
liste3.sort()
print(liste)
print(liste3)
#sort()  tri la liste alphabetiquement ou numeriquement

#TUPLES
tupple = ("Facebook", "instagram", "twitter")
#les tuples sont des sortes de liste mom modifiables

#trouver une element dans une liste ou tuple
boool = 5 in liste3
print(boool)
boool = 10 in liste3
print(boool)

#Un dictionnaire est une structure de données qui enregistre des données dans des paires clés-valeurs.
dictionnaire = {"responsable":"jeanne d'arc", "youyou":"yopyop"}

nouvelle_campagne = {
"responsable_de_campagne": "Jeanne d'Arc",
"nom_de_campagne": "Campagne nous aimons les chiens",
"date_de_début": "01/01/2020",
"influenceurs_importants": ["@MonAmourDeChien", "@MeilleuresFriandisesPourChiens"]
}

#on peut aussi creer un dictionnaire vide et associer des ensembles cle: valeur
taux_de_conversion = {}
taux_de_conversion['facebook'] = 3.4
taux_de_conversion['instagram'] = 1.2
#ou sinon avec la fonction dict()
taux_de_conversion = dict()
taux_de_conversion['facebook'] = 3.4
taux_de_conversion['instagram'] = 1.2

print(dictionnaire)
print(taux_de_conversion)
print(dictionnaire["responsable"])
#supprimer une cle:valeur avec del ou pop()
del taux_de_conversion["facebook"]
taux_de_conversion.pop("instagram")
print(taux_de_conversion)

#verifier l'existence d'une cle avec in
bol = "facebook" in taux_de_conversion
print(bol)
bol = "responsable" in dictionnaire
print(bol)

#les SETS
# les set sont comme les dictionnaire mais chaque element et unique et immuable
# on peut stocker dans les set des string, des nb, des tuples mais pas de liste ou de dico
#le set peut etre modifier, on peut ajouter ou enlever des objets
#on peut creer un set avec la fonction set() ou avec {}
foot = set(["angers", "bordeaux", "brest"])
#on peut utiliser toutes les fonctions des list sur set
#un set est non ordonne
foot.remove("bordeaux")
foot.add("le havre")
print(foot)

ensoleille = True
neige = False
florcon = True
#les conditions
if ensoleille:
    print("on va a la plage !")
elif neige:
    print("on va faire un bonhomme de neige !")
else:
    print("boulo")
#si c vrai alor on fait la condition

if ensoleille and neige:
    print("plage")
elif florcon and not neige:
    print("on")
elif florcon or neige:
    print("boule")

fruit = "pomme"
#MATCH CASE
match fruit:
    case "banane":
        print("banane")
    case "pomme":
        print("pomme")
    case _:
        print("??")

# boucle

dernier = ["hello", "opto", "world", "vgvg"]
for souris in dernier:
    print(souris)
#souris et le nom d'une variable
#la fonction range() Elle renverra une séquence de nombres qui vont de 0 à un nombre de fin déterminé.
#on peut saisir un nombre dans la fonction  range()  , et qu’elle renvoie une séquence de nombres allant de 0 à ce nombre moins un
for x in range(5):
    print(x)

capacite_maximale = 10
capacite_actuelle = 3
while capacite_actuelle < capacite_maximale:
    capacite_actuelle += 1

liste = [1, 2, 3, 4, 5]
# Boucle for sur la liste
for element in liste:
    if element == 3:
        # Si l'élément vaut 3, on passe à l'itération suivante sans exécuter le reste du code
        continue
    # Dans tous les autres cas, on exécute le reste du code
    print(element)
