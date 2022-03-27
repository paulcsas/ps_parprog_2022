close all
clear all
clc

set(0, 'defaultTextInterpreter', 'latex'); 

%% ParProg assignment 02 

% times, no optimization flag
cores =             [     1,      2,      3,      4,      5,      6,      7,      8];
comparison =        [18.575,  9.300, 6.2021, 4.6525, 3.7242, 3.1075, 2.6613, 2.3388]; 


figure(1)
plot(cores, comparison,'Linewidth', 1.5, 'Displayname', 'pthread');
xlabel('$threads$');
ylabel('$time$ $(s)$')
hold on
plot(1, 18.3100,'--*', 'Displayname', 'serial')
hold off
leg = legend();
set(leg, 'Interpreter', 'latex','Location','northeast');
pbaspect([1.61 1 1])
