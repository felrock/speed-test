import matplotlib.pyplot as plt
import numpy as np
import scipy.stats as stats
import math
import sys

mu_1 = 0.084809
sig_1 = 9.19915
x1 = np.linspace(mu_1 - 3*sig_1, mu_1 + 3*sig_1, 100)

mu_2 = 0.05888
sig_2 = 7.66597
x2 = np.linspace(mu_2 - 3*sig_2, mu_2 + 3*sig_2, 100)



plt.plot(x1, stats.norm.pdf(x1, mu_1, sig_1), color='green')
plt.plot(x2, stats.norm.pdf(x2, mu_2, sig_2), color='red')
plt.savefig("to_string.jpg")