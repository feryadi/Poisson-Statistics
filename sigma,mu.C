{
   auto c4 = new TCanvas("c4","c4",200,10,600,400);
   double x[] = {3.45, 10.65, 2.66, 7.94};
   double y[] = {3.267, 11.86, 2.45,  8.94};
   double ex[] = {0.06, 0.09,  0.06, 0.07};
   double ey[] = {0.30, 2.21, 0.22, 1.41};
   
   gStyle->SetOptFit(1111);
   
   TGraphErrors* h = new TGraphErrors(4, x, y, ex, ey);
   
   h->Fit("pol1");
   
   h.GetYaxis().SetTitle("#sigma");
   h.GetXaxis().SetTitle ("#sqrt{#mu}");
   
   
   h->Draw("ap");
   
}