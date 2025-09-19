from give_bmi import give_bmi, apply_limit


height = [2, 5]
weight = [16, 38]
bmi = give_bmi(height, weight)
print(bmi, type(bmi))
print(apply_limit(bmi, 5))
