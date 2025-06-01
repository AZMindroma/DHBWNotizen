from IPython.core.display import HTML


class Test:

    def __init__(self, test_name):
        self.name = test_name
        self.result = '<h3>' + test_name + '</h3>'
        self.success = True


    def equals(self, name, actual, expected):
        if actual == expected:
            self.result = self.result + '<p>' + name + '=' + str(actual) + ' ✅</p>'
        else:
            self.result = self.result + '<p>' + name + '=' + str(actual) + ' ❌ (erwartet: ' + name + '=' + str(expected) + ')</p>'
            self.success = False
        return self
    
    def __str__(self):
        return self.result

    def __repr__(self):
        return self.result

    def report(self):
        return HTML('<div class="alert alert-block ' + ('alert-success' if self.success else 'alert-danger') + '">' 
            + self.result 
            + "</div>")

    
    

    
    
