from setuptools import find_packages
from setuptools import setup

setup(
    name='autopartol_interface',
    version='0.0.0',
    packages=find_packages(
        include=('autopartol_interface', 'autopartol_interface.*')),
)
