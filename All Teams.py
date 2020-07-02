import itertools

player_list = []

category = ['wk', 'bat', 'allr', 'bowl']
teams = [1, 2]
must = []

def getInput():
    for t in teams:
        print("\nEnter Information for Team", t, '\n')
        for cat in category:
            print("Enter", cat, "names followed by credits :")
            print("Enter 0 to move to next category.. No spaces in names plzzz..")
            while True:
                inp = input()
                if inp == '0': break
                name, credit = inp.split()    
                credit = float(credit)
                if name[-1] == '*':
                    name = name[: -1]
                    must.append(name)
                player_list.append((name, t, credit, cat))


getInput()

tot = len(player_list)
team_size = 11

possible = list(itertools.combinations(player_list, team_size))

print(len(possible), ' total teams')

def valid(team):
    maxCr = 100
    cr = t1 = t2 = wk = bat = bowl = allr = 0
    cnt = 0
    for player in team:
        if player[0] in must: cnt += 1
        if player[1] == 1: t1 += 1
        else: t2 += 1
        cr += player[2]
        cat = player[3]
        if cat == 'wk': wk += 1
        elif cat == 'bat': bat += 1
        elif cat == 'allr': allr += 1
        elif cat == 'bowl': bowl += 1
    if cr > maxCr: return False
    if t1 > 7 or t2 > 7: return False
    if wk != 1: return False
    if bat < 3: return False
    if allr < 1: return False
    if bowl < 3: return False
    #print(cr, t1, t2, wk, bat, allr, bowl)
    return cnt == len(must)
        


valid_teams = []
for p in possible:
    if valid(p):
        valid_teams.append(p)

'''
for vt in possible:
    print(sum(player[2] for player in vt))
'''

valid_players = []
for vt in valid_teams:
    cur = []
    for player in vt:
        cur.append(player[0])
    valid_players.append(cur)

for i in range(len(valid_players)):
    print("Team ", i + 1, ': ')
    print(valid_players[i])
    print('\n')