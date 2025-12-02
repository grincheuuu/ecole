import time
import datetime

date = time.time()
dat = datetime.date.today()
# , separateur des milliers
# .4f, 4 chiffre apres la virgules
print(f"Seconds since January 1, 1970: {date:,.4f} or {date:.2e}", end="")
print(" in scientific notation")
print(dat.strftime("%B %d %Y"))
