#encoding=utf8
import numpy as np
def mse_score(y_predict,y_test):
    '''
    input:y_predict(ndarray):预测值
          y_test(ndarray):真实值
    ouput:mse(float):mse损失函数值
    '''
    #********* Begin *********#
    mse = np.mean(y_predict-y_test)
    #********* End *********#
    return mse
class LinearRegression :
    def __init__(self):
        '''初始化线性回归模型'''
        self.theta = None
    def fit_normal(self,train_data,train_label):
        '''
        input:train_data(ndarray):训练样本x
              train_label(ndarray):训练标签y
        '''
        #********* Begin *********#
        x = np.hstack([np.ones((len(train_data),1)),train_data])
        self.theta =np.linalg.inv(x.T.dot(x)).dot(x.T).dot(train_label)
        #********* End *********#
        return self.theta
    def predict(self,test_data):
        '''
        input:test_data(ndarray):测试样本
        '''
        #********* Begin *********#
        x = np.hstack([np.ones((len(test_data),1)),test_data])
        return x.dot(self.theta)
        #********* End *********#