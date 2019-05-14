{
	
  gStyle->SetOptFit(1111);
  
  TF1 *f = new TF1("f", "[0]*TMath::Poisson(x,[1])", 0, 14);
  TF1 *g = new TF1("g","gaus", 0, 14);
  f.SetParameters(2, 10); 
  
  TH1F *h = new TH1F("Poisson", "Number of decay distribution (1 sec)", 14, 0, 14);
  TH1F *h1 = (TH1F*)(h->Clone());
  h1->SetName("Gaussian");
  
  float data1[100]={4,5,10,4,1,11,3,4,8,12,8,4,6,5,3,9,7,8,5,4,7,8,4,10,7,9,6,3,13,8,3,9,11,4,7,11,7,9,6,5,5,3,7, + 
  10,3,8,6,5,9,6,9,3,9,8,11,4,7,8,4,6,7,4,7,5,5,2,8,6,5,4,11,5,12,8,5,5,5,6,6,4,6,10,6,8,7,5,6,9,5,9,4,3,3,4,8,8, + 
  6,4,8,7};
 
 for (int i=0; i<100; i++){
	  h->Fill(data1[i]);
	  h1->Fill(data1[i]);
  }
 
  h->SetFillColor(4);
  f->SetLineColor(3);
  
  h->Fit(f, "R"); 
  h1->Fit(g, "+"); 
  
  h.GetYaxis().SetTitle("N");
  h.GetXaxis().SetTitle ("Number of decays ");
  
  h.Draw();
  h1->Draw("sames");
}