# simple_network_for_practice.png 기준으로 작성한 모델

# for one sample (x,y)
# s = wx + b
# e = (s - y) ^ 2
# de/dw = ds/dw * de/ds = x * 2(s-y)
# de/db = ds/db * de/ds = 1 * 2(s-y)

# for batch samples
# (grad_w, grad_b) = average (de/dw, de/db) over samples in batch
# because loss function for the batch is the average of the loss of each sample

# update
# w -= grad_w * learning_rate
# b -= grad_b * learning_rate

import numpy as np
import matplotlib.pyplot as plt


class FNN:
    def __init__(self, lr=0.01):
        self.lr = lr  # learning rate
        self.w = 0.5  # weight
        self.b = 0.0  # bias

    # forward propagation
    def predict(self, x):
        return self.w * x + self.b

    # train for one batch and update weight
    def train_on_batch(self, x, y):
        batch_size = x.shape[0]

        # batch forward propagation
        s = self.w * x + self.b

        grad_sum_b = 0.0
        grad_sum_w = 0.0
        for i in range(batch_size):
            dedb = 2 * (s[i] - y[i])
            dedw = x[i] * dedb
            grad_sum_b += dedb
            grad_sum_w += dedw

        grad_avg_b = grad_sum_b / batch_size
        grad_avg_w = grad_sum_w / batch_size

        # batch gradient descent
        self.w -= self.lr * grad_avg_w
        self.b -= self.lr * grad_avg_b

    def fit(self, x, y, batch_size, epochs, validation_data):
        errors = []  # validation loss after each epoch

        for i in range(epochs):
            for j in range(0, x.shape[0], batch_size):
                self.train_on_batch(x[j: j + batch_size], y[j: j + batch_size])
            e = np.mean(np.square(self.predict(validation_data[0]) - validation_data[1]))
            errors.append(e)
            print('weight = ', self.w, ', bias = ', self.b, ', error = ', e)
        return errors


x_train = np.random.rand(1024)
y_train = 2 * x_train + 1

x_validation = np.random.rand(32)
y_validation = 2 * x_validation + 1

x_test = np.random.rand(256)
y_test = 2 * x_test + 1

fnn = FNN(0.01)
errors = fnn.fit(x_train, y_train, 32, 300, (x_validation, y_validation))
# fit method는 epoch 끝날 때 마다 error 값 반환

y_pred = fnn.predict(x_test)
# print('y_pred')
# print(y_pred)
#
# print('\n\ny_test')
# print(y_test)

plt.plot(errors)
plt.xlabel('epoch')
plt.ylabel('MSE')
plt.show()
