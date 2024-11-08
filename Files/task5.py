#
#  task5.py
#
#  Created by Angelos Stavrou
#  Python program to explain os.urandom() method
        
# importing os module
import os
      
# Declaring size
size = 16 # This is in bytes
  
# Using os.urandom() method
result = os.urandom(size)
      
# Print the random bytes string
# Output will be different everytime
print(result.hex())
