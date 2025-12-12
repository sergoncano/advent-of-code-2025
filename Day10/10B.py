from pulp import *


def get_sequence(t):
    t = t.strip("(")
    t = t.strip(")")
    t = t.strip("{")
    t = t.strip("}")
    return list(map(int, t.split(",")))


def convert(buttons):
    res = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for i in range(0, 10):
        if i in buttons:
            res[i] = 1
    return res


def normalize(objective):
    res = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for i in range(0, len(objective)):
        res[i] = objective[i]
    return res


def solve(buttons, objective):
    prob = LpProblem("HousingProblem", LpMinimize)
    x = [LpVariable(f"x{i}", 0, None, cat="Integer") for i in range(len(buttons))]
    for i in x:
        prob += i >= 0
    for i in range(0, 10):
        sum = 0
        for j in range(0, len(buttons)):
            sum += buttons[j][i] * x[j]
        prob += sum == objective[i]
    prob += lpSum(x), "res"
    prob.solve()
    sum = 0
    for i in x:
        sum += value(i)
    for i in x:
        print(i, ":", value(i))
    print("----------------------------------------------")
    print("Buttons:", buttons)
    print("objective:", objective)
    print("result:", sum)
    return sum


result = 0
for i in range(0, 198):  # 198
    line = input()
    parsed_line = line.split()
    buttons = []
    for j in range(1, len(parsed_line) - 1):
        buttons.append(convert(get_sequence(parsed_line[j])))
    objective = get_sequence(parsed_line[-1])
    result += solve(buttons, normalize(objective))
    print("------------------Result", i, result, "----------------")
print("REAL SHIT -------------------------------- ", result)
