% 测试Git
function A = AirlightEstimate(img)
im = rgb2gray(img/255);
flag = 0;
while flag <= 5
    [M, N] = size(im);
    % divided image into 4 rectangular region
    subim{1} = im(1:floor(M/2),1:floor(N/2));subimg{1} = img(1:floor(M/2),1:floor(N/2),:);
    subim{2} = im(1:floor(M/2),floor(N/2)+1:end);subimg{2} = img(1:floor(M/2),floor(N/2)+1:end,:);
    subim{3} = im(floor(M/2)+1:end,1:floor(N/2));subimg{3} = img(floor(M/2)+1:end,1:floor(N/2),:);
    subim{4} = im(floor(M/2)+1:end,floor(N/2)+1:end);subimg{4} = img(floor(M/2)+1:end,floor(N/2)+1:end,:);
    % for each sub-image, calculate its score (mean substract std)
    s(1) = mean2(subim{1}(:,:));
    s(2) = mean2(subim{2}(:,:));
    s(3) = mean2(subim{3}(:,:));
    s(4) = mean2(subim{4}(:,:));
    % choose the region with highest score
    x = find(s == max(s));
    im = subim{x};img = subimg{x};
    flag = flag+1;
end
img = double(img);
% B = mean(mean(im));
A1=mean2(img(:,:,1));A2=mean2(img(:,:,2));A3=mean2(img(:,:,3));
A = [A1 A2 A3];
disp(A);
end