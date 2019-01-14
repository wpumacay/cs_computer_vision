close all;
clear all;
clc

pkg load image;

img = im2double( rgb2gray( imread( 'lena_small.jpeg' ) ) );
_ft = fft2( img );
%_ft_abs = abs( fftshift( _ft ) );
%_ft_labs = log( 1 + _ft_abs );
_ft_shift = fftshift( _ft );
_ft_labs = log( 1 + abs( _ft_shift ) );

figure;
imshow( _ft_labs, [] );
colormap gray;