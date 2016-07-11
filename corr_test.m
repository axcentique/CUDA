% TS = 100*rand(300,5000);
clc

for i=1%:size(TS,2)-1
    tic
    for j=2:size(TS,2)
        out(i,j) = corr2(TS(:,i),TS(:,i));
    end
    i/size(TS,2)
    t = toc;
end

sprintf('%f mins',t*size(TS,2)/60/2)


%%
clc
tic
pdist(TS','correlation');
t = toc;

sprintf('%f mins',t*size(TS,2)/60/2)