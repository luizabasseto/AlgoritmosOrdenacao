import matplotlib.pyplot as plt

algoritmos = [
    "Bubble Sort",
    "Bubble Sort Otimizado",
    "Insertion Sort",
    "Selection Sort",
    "Selection Sort Otimizado"
]

comparacoes_12k = [71994000, 71983704, 35721107, 71994000, 71993922]

fig, ax = plt.subplots(figsize=(12, 6))  
fig.suptitle("Comparações de Algoritmos de Ordenação", fontsize=16, y=0.9)

bars = ax.bar(algoritmos, comparacoes_12k, color='skyblue')
ax.set_title("Vetor com 12 mil elementos", fontsize=13, pad=15)
ax.set_ylabel("Comparações (escala log)", fontsize=11)
ax.tick_params(axis='x', rotation=30)
ax.set_yscale('log')
ax.grid(True, which="both", linestyle="--", linewidth=0.5, alpha=0.7)

for bar in bars:
    altura = bar.get_height()
    ax.text(
        bar.get_x() + bar.get_width() / 2,
        altura * 1.10,
        f'{int(altura):,}'.replace(",", "."),
        ha='center', va='bottom', fontsize=9
    )

plt.tight_layout(rect=[0, 0, 1, 0.95]) 
plt.show()
