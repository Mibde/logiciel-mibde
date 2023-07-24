import sys
import matplotlib.pyplot as plt

# Récupérer les arguments de ligne de commande
args = sys.argv
print("coucou")
# Afficher les arguments
for arg in args:
    print(arg)

x = [1, 2, 3, 4, 5]
y = [2, 4, 6, 8, 10]

# Tracer le graphique
plt.plot(x, y, marker='o')

# Ajouter des étiquettes et un titre
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Graphique de test')
# Afficher le graphique
plt.show()
	

# Données du graphique



