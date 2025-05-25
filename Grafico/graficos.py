import matplotlib.pyplot as plt

algoritmos = [
    "Bubble Puro", "Bubble Otimizado",
    "Selection", "Insertion", "Insertion Otimizado"
]

tempos_15k = [1.52189, 1.84904, 0.696268, 0.498925, 0.849115]
tempos_100k = [77.0487, 104.088, 27.9427, 33.6921, 69.3647]
tempos_200k = [5539.2, 338.786, 122.845, 96.4936, 204.184]

tamanhos = ["15 mil", "100 mil", "200 mil"]

fig, axs = plt.subplots(1, 3, figsize=(18, 5))

axs[0].bar(algoritmos, tempos_15k, color='skyblue')
axs[0].set_title("Tempo de Execução - Vetor com 15 mil elementos")
axs[0].set_ylabel("Tempo (s)")
axs[0].set_xticklabels(algoritmos, rotation=45)

axs[1].bar(algoritmos, tempos_100k, color='orange')
axs[1].set_title("Tempo de Execução - Vetor com 100 mil elementos")
axs[1].set_ylabel("Tempo (s)")
axs[1].set_xticklabels(algoritmos, rotation=45)

axs[2].bar(algoritmos, tempos_200k, color='lightgreen')
axs[2].set_title("Tempo de Execução - Vetor com 200 mil elementos")
axs[2].set_ylabel("Tempo (s)")
axs[2].set_xticklabels(algoritmos, rotation=45)

plt.tight_layout()
plt.show()
