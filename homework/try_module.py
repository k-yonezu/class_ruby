import practice as c_practice
# まずは、動作検証
c_practice.hello_world()

# push
test_list = c_practice.push([50, 51, 52], 53)
print(test_list)

# pop
result = c_practice.pop(test_list)
print(result)
