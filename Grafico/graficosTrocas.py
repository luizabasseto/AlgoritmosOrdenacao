import matplotlib.pyplot as plt

algoritmos = [
    "Bubble Sort",
    "Bubble Sort Otimizado",
    "Insertion Sort",
    "Selection Sort",
    "Selection Sort Otimizado"
]

trocas_12k = [35709112, 35709112, 35709112, 11971, 11971]

fig, ax = plt.subplots(figsize=(10, 6)) 
ax.bar(algoritmos, trocas_12k, color='skyblue')
ax.set_title("Total de Trocas - Vetor com 12 mil elementos", fontsize=13, pad=15)
ax.set_ylabel("Trocas (escala log)", fontsize=11)
ax.tick_params(axis='x', rotation=25)
ax.set_yscale('log')  
ax.grid(True, which="both", linestyle="--", linewidth=0.5, alpha=0.7)

for bar in ax.patches:
    altura = bar.get_height()
    ax.text(
        bar.get_x() + bar.get_width() / 2,
        altura * 1.10,
        f'{int(altura):,}'.replace(",", "."),
        ha='center', va='bottom', fontsize=9
    )

plt.tight_layout()
plt.show()
