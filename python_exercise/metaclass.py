
class ObjectCreator(object):
    pass

my_object = ObjectCreator()

print(my_object)

print(ObjectCreator)

def echo(o):
    print(o)

print(hasattr(ObjectCreator, 'new_attribute'))

ObjectCreator.new_attribute = 'foo'

print(hasattr(ObjectCreator, 'new_attribute'))

print(ObjectCreator.new_attribute)

ObjectCreatorMirror = ObjectCreator

print(ObjectCreatorMirror())

def choose_class(name):
    if name == 'foo':
        class Foo(object):
            pass
        return Foo
    elif name == 'bar':
        class Bar(object):
            pass
        return Bar
    else:
        return None

MyFooClass = choose_class('foo')
print(MyFooClass)

print(type(1))
print(type('1'))
print(type(ObjectCreator))
print(type(ObjectCreator()))

MyShinyClass = type('MyShinyClass', (), {})
print(MyShinyClass)
print(MyShinyClass())

class Foo():
    bar = True
print(Foo)
Foo = type ('Foo', (), {'bar': True})
print(Foo)

class FooChild(Foo):
    pass
print(FooChild)
FooChild = type('FooChild', (Foo,), {})
print(FooChild)

def echo_bar(self):
    print(self.bar)

FooChild = type('FooChild', (Foo,), {'echo_bar': echo_bar})
print(hasattr(Foo, 'echo_bar'))
print(hasattr(FooChild, 'echo_bar'))

my_foo = FooChild()
my_foo.echo_bar()

age = 37
print(age.__class__)
name = 'Bob'
print(name.__class__)
print(echo_bar.__class__)
print(FooChild.__class__)
myFooChild = FooChild()
print(myFooChild.__class__)
print(myFooChild.__class__.__class__)

def upper_attr(future_class_name, future_class_parents, future_class_attr):
    attrs = ((name, value) for name, value in future_class_attr.items() if not name.startswith('__'))
    uppercase_attr = dict((name.upper(), value) for name, value in attrs)
    return type(future_class_name, future_class_parents, uppercase_attr)

class Foo(object):
    __metaclass__ = upper_attr
    bar = 'bip'

print(hasattr(Foo, 'bar'))
print(hasattr(Foo, 'BAR'))

f = Foo()
print(f.bar)

class UpperAttrMetaClass(type):
    def __new__(upperattr_metaclass, future_class_name, future_class_parents, future_class_attr):
        attrs = ((name, value) for name, value in future_class_attr.items() if not name.startswith('__'))
        uppercase_attr = dict((name.upper(), value) for name, value in attrs)
        return type(future_class_name, future_class_parents, uppercase_attr)

class Foo(object):
    __metaclass__ = UpperAttrMetaClass

    bar = 'bip'

print(hasattr(Foo, 'bar'))
print(hasattr(Foo, 'BAR'))

f = Foo()
print(f.bar)


class UpperAttrMetaclass(type):
    def __new__(cls, name, bases, dct):
        attrs = ((name, value) for name, value in dct.items() if not name.startswith('__'))
        uppercase_attr = dict((name.upper(), value) for name, value in attrs)
        return super(UpperAttrMetaclass, cls).__new__(cls, name, bases, uppercase_attr)

