import matplotlib.pyplot as plt

buscas = [
    "Trocas Bubble Sort",
    "Trocas Bubble Sort Otimizado",
    "Trocas Insertion Sort",
    "Trocas Selection Sort",
    "Trocas Selectio Sort Otimizado"
]

trocas_12k = [35709112,35709112,35709112,11971,11971]
trocas_70k = [1223487348,1223487348,1223487348,69911,69911]
trocas_100k = [2506572675,2506572675,2506572675,99887,99887]

fig, axs = plt.subplots(1, 3, figsize=(14, 5))

axs[0].bar(buscas, trocas_12k, color='skyblue')
axs[0].set_title("Total de Trocas de cada Algoritmo para o Vetor com 12 mil elementos")
axs[0].set_ylabel("Trocas (milhões)")
axs[0].tick_params(axis='x', rotation=30)

axs[1].bar(buscas, trocas_70k, color='orange')
axs[1].set_title("Total de Trocas de cada Algoritmo para o Vetor com 70 mil elementos")
axs[1].set_ylabel("Trocas (milhões)")
axs[1].tick_params(axis='x', rotation=30)

axs[2].bar(buscas, trocas_100k, color='green')
axs[2].set_title("Total de Trocas de cada Algoritmo para o Vetor com 100 mil elementos")
axs[2].set_ylabel("Trocas (milhões)")
axs[2].tick_params(axis='x', rotation=30)

plt.tight_layout()
plt.show()