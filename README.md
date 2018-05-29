# L_ASMR

L'objectif de ce projet est de créer un microphone binaural pour faire de l'ASMR.

Lien vers le Trello du projet
https://trello.com/b/Y53wFnGt/lasmr

Le système comportera deux micros pour capter les sons et une prise jack pour les retransmettre. Il sera piloté par un PIC32 pour la partie logicielle, et pourra communiquer avec un Driver sur un Ordinateur grâce à une connexion USB. Il y aura aussi présence d'une carte SD pour le stockage des données.

La tension d'alimentation du projet sera 5V DC pour qu'il puisse fonctionner uniquement grâce à une connexion USB ou bien en fonctionnement sur batterie 5V en cas d'utilisation mobile.

A l'issu de ces travaux, une production CAO d'un boîtier pourra être imprimé en résine. (Annexe) 


### Partie électronique (Altium/Eagle)
- Choix des composants utilisés
- Rédaction des plans du montage électronique
- Mise en fonctionnement du montage
- Production d'un circuit imprimé

### Partie logicielle (C/C++ & Framework JUCE)
- Traitement du son reçu par les micros
- Traitement du son transmis par la sortie jack
- Stockage des données sur la carte SD
- Driver USB pour communiquer avec le projet
- Génération de sons standards (par ex. le bruit blanc/rose, le tic-tac d'horloge...)

### Partie CAO (AutoCAD/Blender)
- Dessiner un boîtier avec un design spécifique (oreilles, tête, boîte...)
- Impression 3D