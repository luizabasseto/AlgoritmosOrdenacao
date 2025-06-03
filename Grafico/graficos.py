import matplotlib.pyplot as plt

algoritmos = [
    "Bubble Puro", "Bubble Otimizado",
    "Selection", "Selection Otimizado", "Insertion"
]

tempos_12k = [1.33083, 1.45114, 0.702620, 1.24734, 0.435547]
tempos_70k = [111.310902, 47.826009, 18.218173, 39.969767, 15.741638]
tempos_100k = [214.831378, 232.451618, 90.830032, 213.950280, 73.401721]

tamanhos = ["12 mil", "70 mil", "100 mil"]

fig, axs = plt.subplots(1, 3, figsize=(18, 5))

axs[0].bar(algoritmos, tempos_12k, color='skyblue')
axs[0].set_title("Tempo de Execução - Vetor com 12 mil elementos")
axs[0].set_ylabel("Tempo (s)")
axs[0].set_xticklabels(algoritmos, rotation=45)

axs[1].bar(algoritmos, tempos_70k, color='orange')
axs[1].set_title("Tempo de Execução - Vetor com 70 mil elementos")
axs[1].set_ylabel("Tempo (s)")
axs[1].set_xticklabels(algoritmos, rotation=45)

axs[2].bar(algoritmos, tempos_100k, color='lightgreen')
axs[2].set_title("Tempo de Execução - Vetor com 100 mil elementos")
axs[2].set_ylabel("Tempo (s)")
axs[2].set_xticklabels(algoritmos, rotation=45)

plt.tight_layout()
plt.show()
