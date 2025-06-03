import matplotlib.pyplot as plt

algoritmos = [
    "Bubble Sort",
    "Bubble Sort Otimizado",
    "Insertion Sort",
    "Selection Sort",
    "Selection Sort Otimizado"
]

trocas_12k = [35709112, 35709112, 35709112, 11971, 11971]
trocas_70k = [1223487348, 1223487348, 1223487348, 69911, 69911]
trocas_100k = [2506572675, 2506572675, 2506572675, 99887, 99887]

fig, axs = plt.subplots(1, 3, figsize=(18, 6))

cores = ['skyblue', 'orange', 'green']

titulos = [
    "Vetor com 12 mil elementos",
    "Vetor com 70 mil elementos",
    "Vetor com 100 mil elementos"
]
dados = [trocas_12k, trocas_70k, trocas_100k]

for i in range(3):
    axs[i].bar(algoritmos, dados[i], color=cores[i])
    axs[i].set_title(f"Total de Trocas - {titulos[i]}")
    axs[i].set_ylabel("Trocas (escala log)")
    axs[i].tick_params(axis='x', rotation=25)
    axs[i].set_yscale('log')  

plt.tight_layout()
plt.show()
