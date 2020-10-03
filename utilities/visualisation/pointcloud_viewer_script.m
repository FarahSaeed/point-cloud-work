% input point cloud and labels
disp(size(ptLabeling)); 

xx = [];
yy = [];
zz = [];
clr = [];
for c = 1:25
    disp(c);
	% combining x coordinate of all points
    xx1 = ptLabeling{c,1}(:,1); 
    xx = [xx(:); xx1(:)];
    
	% combining y coordinate of all points
    yy1 = ptLabeling{c,1}(:,2); 
    yy = [yy(:); yy1(:)];
    
	% combining z coordinate of all points
    zz1 = ptLabeling{c,1}(:,3); 
    zz = [zz(:); zz1(:)];
    
	% red color for points with 0 label
    if ptLabeling{c,2} == 0		 
     clrr = [255.0, 0.0, 0.0]; 
	 
	% green color for points with 1 label
    elseif ptLabeling{c,2} == 1  
     clrr = [0.0, 255.0, 0.0];

	% blue color for points with 2 label
    else                         
     clrr = [0.0, 0.0, 255.0];
    end;
    
    clr = [clr ; repmat(clrr,size(xx1,1),1)];
    
end;

% visualize point cloud
figure;
pcshow([xx(:),yy(:),zz(:)],clr); 
xlabel('X');
ylabel('Y');
zlabel('Z');