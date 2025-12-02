# Push_swap

<div align="center">
  <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/push_swapm.png" alt="Push_swap Badge"/>
</div>

## 📝 Résumé

**push_swap** est un projet de tri algorithmique où l'objectif est de trier des données dans une pile en utilisant un ensemble limité d'instructions, tout en visant le plus petit nombre d'actions possible. Ce projet nécessite de travailler avec différents algorithmes et de choisir le plus approprié pour un tri de données optimisé
**Objectifs principaux :**
- Créer un programme capable de trier une pile d'entiers avec un nombre minimum d'opérations (imposé par le sujet)
- Maîtriser les concepts de structures de données (piles)
- Comprendre et implémenter des algorithmes de tri efficaces

---

## Le Défi
Vous disposez de :
- 2 piles nommées **a** et **b**
- Un ensemble d'entiers aléatoires (positifs et/ou négatifs) dans la pile **a**
- La pile **b** est vide au départ

**Objectif :** Trier les nombres dans la pile **a** en ordre croissant avec le minimum d'opérations possible.

---

## 🔧 Installation

### Cloner le projet

```bash
git clone https://github.com/mello-sdn/Push_swap.git
cd push_swap
```

### Compilation

```bash
make
```

## 💻 Utilisation

### Programme push_swap

```bash
# Exemple basique
./push_swap 2 1 3 6 5 8
# Sortie : liste d'instructions pour trier les nombres
sa
pb
pb
pb
sa
pa
pa
pa

# Gestion d'erreurs basique
./push_swap 0 one 2 3
Error
```

### Vérification avec checker

```bash
# Avec le checker fourni
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
Resultat attendu : OK
```

---

## 📚 Points clés à retenir & Ressource

### Concepts Algorithmiques
- **Complexité** : Comprendre et optimiser la complexité temporelle de votre algorithme
- **Choix d'algorithme** : Différentes approches selon le nombre d'éléments (tri à bulles, tri rapide, radix sort, etc.) j'ai personnellement choisi le Turkish Algo 
- **Optimisation** : Minimiser le nombre d'opérations nécessaires

### Structures de Données
- Implémenter et manipuler des piles (stacks)
- Gérer efficacement les opérations sur les piles
- Comprendre LIFO (Last In, First Out)

### Gestion d'Erreurs
- Arguments non entiers
- Arguments dépassant les limites d'un int
- Présence de doublons
- Chaînes vides

### Ressource
- [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)
- [push-swap-tester](https://github.com/gemartin99/Push-Swap-Tester)
- [Turkish Algorithm](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)

---

### Conseils
- Commencez par implémenter toutes les opérations
- Testez chaque opération individuellement
- Développez d'abord un algorithme simple qui fonctionne
- Optimisez progressivement
- Utilisez des visualiseurs pour débugger

---

## ✨ Note Finale
<br>
  <img width="199" height="170" alt="125" src="https://github.com/user-attachments/assets/c127bd3f-6bda-4633-80a0-b4efb9a120d6" />




