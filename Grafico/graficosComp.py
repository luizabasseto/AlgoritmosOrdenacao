import matplotlib.pyplot as plt

algoritmos = [
    "Bubble Sort",
    "Bubble Sort Otimizado",
    "Insertion Sort",
    "Selection Sort",
    "Selection Sort Otimizado"
]

comparacoes_12k = [71994000, 71983704, 35721107, 71994000, 71993922]
comparacoes_70k = [2449965000, 2449947980, 1223557343, 2449965000, 2449962074]
comparacoes_100k = [4999950000, 4999880994, 2506672670, 4999950000, 4999944435]

titulos = [
    "Vetor com 12 mil elementos",
    "Vetor com 70 mil elementos",
    "Vetor com 100 mil elementos"
]
dados = [comparacoes_12k, comparacoes_70k, comparacoes_100k]
cores = ['skyblue', 'orange', 'green']

fig, axs = plt.subplots(1, 3, figsize=(22, 6))
fig.suptitle("Comparações de Algoritmos de Ordenação", fontsize=16, y=1.05)

for i in range(3):
    bars = axs[i].bar(algoritmos, dados[i], color=cores[i])
    axs[i].set_title(titulos[i], fontsize=12)
    axs[i].set_ylabel("Comparações (escala log)", fontsize=10)
    axs[i].tick_params(axis='x', rotation=30)
    axs[i].set_yscale('log')
    axs[i].grid(True, which="both", linestyle="--", linewidth=0.5, alpha=0.7)

    # Adiciona os valores em cima das barras
    for bar in bars:
        altura = bar.get_height()
        axs[i].text(bar.get_x() + bar.get_width() / 2, altura * 1.05,
                    f'{int(altura):,}'.replace(",", "."),
                    ha='center', va='bottom', fontsize=8, rotation=90)

plt.subplots_adjust(wspace=0.3)
plt.tight_layout()
plt.show()
