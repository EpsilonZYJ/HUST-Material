#encoding=utf8
import numpy as np
#mse
def mse_score(y_predict,y_test):
    #********* Begin *********#
    mse = np.mean((y_predict-y_test)**2)
    #********* End *********#
    return mse
#r2
def r2_score(y_predict,y_test):
    '''
    input:y_predict(ndarray):预测值
          y_test(ndarray):真实值
    output:r2(float):r2值
    '''
    #********* Begin *********#
    r2 =1-mse_score(y_predict,y_test)/np.var(y_test)
    #********* End *********#
    return r2
class LinearRegression :
    def __init__(self):
        '''初始化线性回归模型'''
        self.theta = None
    def fit_normal(self,train_data,train_label):
        '''
        input:train_data(ndarray):训练样本
              train_label(ndarray):训练标签
        '''
        #********* Begin *********#
        x = np.hstack([np.ones((len(train_data),1)),train_data])
        self.theta =np.linalg.inv(x.T.dot(x)).dot(x.T).dot(train_label)
        #********* End *********#
        return self
    def predict(self,test_data):
        '''
        input:test_data(ndarray):测试样本
        '''
        #********* Begin *********#
        x = np.hstack([np.ones((len(test_data),1)),test_data])
        return x.dot(self.theta)
        #********* End *********#
