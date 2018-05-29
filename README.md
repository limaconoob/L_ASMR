# L_ASMR

L'objectif de ce projet est de cr�er un microphone binaural pour faire de l'ASMR.

Lien vers le Trello du projet
https://trello.com/b/Y53wFnGt/lasmr

Le syst�me comportera deux micros pour capter les sons et une prise jack pour les retransmettre. Il sera pilot� par un PIC32 pour la partie logicielle, et pourra communiquer avec un Driver sur un Ordinateur gr�ce � une connexion USB. Il y aura aussi pr�sence d'une carte SD pour le stockage des donn�es.

La tension d'alimentation du projet sera 5V DC pour qu'il puisse fonctionner uniquement gr�ce � une connexion USB ou bien en fonctionnement sur batterie 5V en cas d'utilisation mobile.

A l'issu de ces travaux, une production CAO d'un bo�tier pourra �tre imprim� en r�sine. (Annexe) 


### Partie �lectronique (Altium/Eagle)
- Choix des composants utilis�s
- R�daction des plans du montage �lectronique
- Mise en fonctionnement du montage
- Production d'un circuit imprim�

### Partie logicielle (C/C++ & Framework JUCE)
- Traitement du son re�u par les micros
- Traitement du son transmis par la sortie jack
- Stockage des donn�es sur la carte SD
- Driver USB pour communiquer avec le projet
- G�n�ration de sons standards (par ex. le bruit blanc/rose, le tic-tac d'horloge...)

### Partie CAO (AutoCAD/Blender)
- Dessiner un bo�tier avec un design sp�cifique (oreilles, t�te, bo�te...)
- Impression 3D