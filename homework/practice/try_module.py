import practice as c_practice
# まずは、動作検証
c_practice.hello_world()

c_practice.system("ls -l")
status = c_practice.system("ls -l")

# push
test_list = c_practice.push([50, 51, 52], 53)
print(test_list)

print(test_list.first)

# pop
result = c_practice.pop(test_list)
print(result)

print(status)
