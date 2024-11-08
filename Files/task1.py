#
#  task1.py
#
#
#  Created by Angelos Stavrou

# generate random integer values
from random import seed
from random import getrandbits
import time
# seed random number generator
print(time.time())
#seed(time.time())
# generate some integers
value = [0] * 16
for index in range(16):
   value[index] = getrandbits(8)

print ('[{}]'.format(', '.join(hex(x) for x in value)))
