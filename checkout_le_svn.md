Pour tous ceux qui aurais la flemme de rechercher comment on fait...
N'hésitez pas a modifier/compléter cette page si vous utiliser un autre logiciel de svn

J'ai tester et approuver ce svn avec deux logiciel **Tortoisesvn** et **Kdesvn**.
J'ai aussi reussi a correctement check out les fichier depuis la VM

Note pour tortoise, si vous n'avez aucune icone dans le menu du clique droit, c'est que vous avez probablement installer version 32 bits sur un systeme 64 bits...

Sous linux : vous devez installer subversion et kdesvn pour que ca fonctionne (kdesvn n'est qu'une surcouche de svn)

### **1+** Crée un dossier ou vous voulez récupéré le projet. ###

La ou voulez taffer dessus

### **2+** Configurer le Proxy sur le svn : ###

- Sur tortoise svn (Windows) : clique droit sur le dossier => tortoiseSvn => settings => network


- Sur Kdesvn (Linux) ET sur la VM:{

+ editer le fichier ~/.subversion/servers

+ allez tout en bas du fichier au niveau de [global](global.md)

+ retirer les # **et les espace** devant les ligne qui commence par http-proxy

+ replisser les lignes...}



Dans les deux cas j'ai utiliser ces parametres là :

host: proxies.epitech.net

port: 3128

user et mdp socks

### **3+** Faire le Check out depuis le serveur vers votre pc. ###

#  sur tortoise svn : clique droit sur le dossier, Svn checkout.

#  sur kdesvn : cliquer sur l'icône checkout dans le panneau principal (il est peut être cacher parce que vous avez une fenêtre trop petite).

#  sur la VM : rentrer la commande indiquer dans l'onglet source.

voici l'adresse depuis laquelle vous devez recup le site : https://epi-gamerush.googlecode.com/svn/trunk/

Pour kdesvn vous devez préciser le dossier d'arriver (celui que vous avez crée a l'étape 1)

### **4+** S'authentifier lors du Check out ###

Avant cela, tortoise svn vous demanderas de valider la clee de cryptage utiliser par l'https.

Au bout d'un moment on vous demandera votre login et mdp, vous les trouverez dans **l'onglet source du projet.**

vala vala