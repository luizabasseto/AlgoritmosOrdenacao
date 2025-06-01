import matplotlib.pyplot as plt

# Tipos de buscas
buscas = [
    "Linear Não Ordenado",
    "Binária Não Ordenado",
    "Linear Ordenado",
    "Binária Ordenado"
]

# Tempos médios de execução (em microsegundos)
tempos_12k = [1.902, 0.330, 0.545, 0.397]
tempos_70k = [1.912, 0.382, 2.068, 0.266]

# Criação dos gráficos
fig, axs = plt.subplots(1, 2, figsize=(14, 5))

# Gráfico para 12 mil elementos
axs[0].bar(buscas, tempos_12k, color='skyblue')
axs[0].set_title("Tempo Médio de Execução - Vetor com 12 mil elementos")
axs[0].set_ylabel("Tempo (microsegundos)")
axs[0].tick_params(axis='x', rotation=30)

# Gráfico para 70 mil elementos
axs[1].bar(buscas, tempos_70k, color='orange')
axs[1].set_title("Tempo Médio de Execução - Vetor com 70 mil elementos")
axs[1].set_ylabel("Tempo (microsegundos)")
axs[1].tick_params(axis='x', rotation=30)

plt.tight_layout()
plt.show()