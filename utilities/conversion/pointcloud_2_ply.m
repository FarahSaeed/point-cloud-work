disp(size(ptLabeling));

xx = [];
yy = [];
zz = [];
clr = [];
for c = 1:25
    disp(c);
    xx1 = ptLabeling{c,1}(:,1);
    xx = [xx(:); xx1(:)];
    
    yy1 = ptLabeling{c,1}(:,2);
    yy = [yy(:); yy1(:)];
    
    zz1 = ptLabeling{c,1}(:,3);
    zz = [zz(:); zz1(:)];
    
    if ptLabeling{c,2} == 0
    clrr = [255.0, 0.0, 0.0];
    elseif ptLabeling{c,2} == 1
     clrr = [0.0, 255.0, 0.0];
    else
     clrr = [0.0, 0.0, 255.0];
    end;
    
    clr = [clr ; repmat(clrr,size(xx1,1),1)];
    
end;

disp(size(xx(:)));
disp(size(yy));
disp(size(zz));
disp(size(clr));
pts = [xx yy zz clr];
disp('Heres final size:')
disp(size(pts));
if ptLabeling{2,2} == 1
    disp('yess')
end;

%csvwrite('a1.txt',pts)
pc_obj = pointCloud([xx(:),yy(:),zz(:)],'Color',clr);
pcwrite(pc_obj,'SPL_0511','PLYFormat','ascii');

% xx = [xx(:); aa(:)];
% xx = [xx(:); aa(:)];
% disp(size(xx));
% alpha = [ 1 2 3 4 5];
% disp(size(alpha));
% 
% figure;
% % pcshow([xx(:),yy(:),zz(:)],clr);
% pcshow(pc_obj);
% title('Sphere with Default Color Map');
% xlabel('X');
% ylabel('Y');
% zlabel('Z');