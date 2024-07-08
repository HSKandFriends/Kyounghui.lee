# Kyounghui.lee
코딩 테스트 연습.


# Stack
스택은 LIFO(후입 선출)을 의미합니다.
스택이 가지는 method는 총 3가지(혹은 4가지)

1. Push(value) - Stack에 값을 밀어 넣습니다.
2. Pop() - 가장 마지막 숫자를 제거하면서 값을 확인합니다.
3. Top() - 가장 마지막 숫자의 값을 확인합니다.
(4. Len() - 현재 스택에 밀어넣어진 값의 개수를 확인합니다.)

스택을 구현하는 방법은 대표적으로 2가지로, 하나는 Array로, 하나는 Linked List로 구현하는 것입니다.
Array로 구현하는 경우는 길이가 정해져 있는 단점이 있지만 속도가 빠르다는 강점이 있습니다.
반대로, Linked List로 구현하는 경우 memory가 허락하는 한 무한대의 길이를 가질 수 있지만 속도가 느리다는 단점이 있습니다.(Cache Hit/Miss에 대해 공부해 보세요!)

Python으로 간단하게 구현해 보고 시간이 남는다면 C언어로도 구현해 보세요.


# Queue
큐는 FIFO(선입 선출)을 의미합니다.
큐가 가지는 method는 총 3가지(혹은 4가지)

1. Append(value) - Queue에 값을 밀어 넣습니다.
2. Remove() - 가장 앞에 입력된 숫자를 제거하면서 값을 확인합니다.
3. Head() - 가장 앞에 입력된 숫자를 확인합니다.
(4. Len() - 현재 큐에 밀어넣어진 값의 개수를 확인합니다.)

큐를 구현하는 방법 역시 스택과 동일합니다.
다만, 큐에 Linked List를 활용하는 방법은 일반적으로 권장하지 않습니다. 그 이유는, Tail을 알 수 없는 Linked List의 특징 때문입니다.
Linked List를 사용하려면 Singly Linked List가 아닌 Doubly Linked List를 사용하는 것을 권장하며, 이 경우 Queue 보다는 양방향 Append/Remove가 가능한 Deque(Double Ended Queue)를 구현하길 권장합니다.
