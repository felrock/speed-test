import matplotlib.pyplot as plt
import sys

if len(sys.argv) < 2:
    print('Usage: gen_img.py <input csv file> <output image file>')
    sys.exit()

plt.figure(figsize=(6,3))
file_res = open(sys.argv[1])

ticks = []
i = 0
for line in file_res:

    vals = line.split(', ')
    mu = float(vals[1])
    sig = float(vals[2])
    ticks.append(vals[0])

    # set color depending on implementation
    color = 'blue' if 'std' in vals[0] else 'red'

    plt.errorbar(mu, i, xerr=sig, fmt='o', color=color, capsize=5,
                markersize=8)
    i += 1

plt.yticks([n for n in range(i)], ticks)
plt.tight_layout()
plt.subplots_adjust(bottom=0.15, top=0.92)
plt.title('String & int conversions')
plt.xlabel('Mean time(ns)')
plt.savefig('images/'+sys.argv[2])