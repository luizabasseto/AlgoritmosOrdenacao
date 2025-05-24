import matplotlib.pyplot as plt
import numpy as np

# Dados
algoritmos = [
    'Bubble Otim.', 'Bubble Puro', 'Selection',
    'Insertion', 'Insertion Otim.'
]
tempos = [1.84904, 1.52189, 0.696268, 0.498925, 0.849115]

# Gráfico de barras
plt.figure(figsize=(10, 6))
plt.bar(algoritmos, tempos, color='skyblue')
plt.ylabel('Tempo de Execução (s)')
plt.title('Tempo por Algoritmo (Entrada = 15000)')
plt.grid(axis='y')
plt.tight_layout()
plt.show()
