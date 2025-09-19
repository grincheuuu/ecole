from setuptools import setup, find_packages

setup(
    name='ft_package',
    version='0.0.1',
    packages=find_packages(),
    url="https://github.com/guillaumeschwartz76",
    description='Un package de test simples',
    author='gschwart',
    author_email='gschwart@student.42lehavre.fr',
    license='MIT',
    classifiers=[
        'Programming Language :: Python :: 3',
        'License= :: OSI Approved :: MIT License',
        'Operating System :: OS Independent'
    ],
    python_requires='>=3.6',
    install_requires=[],
)
