from collections import deque
def solution(bridge_length, weight, truck_weights):
    cnt = 0
    bridge = [0] * bridge_length
    truck = deque(truck_weights)
    currentWeight = 0

    while len(truck) > 0:
        cnt+=1
        # print(bridge)
        # print(truck)
        currentWeight = currentWeight - bridge.pop(0)
        if currentWeight + truck[0] <= weight:
            currentWeight += truck[0]
            bridge.append(truck.popleft())
        else:
            bridge.append(0)
    return cnt+len(bridge)
        
bridge_length = 2
weight = 10
truck_weight = [7,4,5,6]
print(solution(bridge_length, weight, truck_weight))

bridge_length = 100
weight = 100
truck_weight = [10]
print(solution(bridge_length, weight, truck_weight))

bridge_length = 100
weight = 100
truck_weight = [10,10,10,10,10,10,10,10,10,10]
print(solution(bridge_length, weight, truck_weight))