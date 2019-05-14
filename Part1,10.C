{
	
  gStyle->SetOptFit(1111);
  
  TF1 *f = new TF1("f", "[0]*TMath::Poisson(x,[1])", 90, 140);
  TF1 *g = new TF1("g","gaus",90, 140);
  f.SetParameters(10, 100); 
  
  TH1F *h = new TH1F("Poisson", "Number of decay distribution (10 secs)", 20, 90, 140);
  TH1F *h1 = (TH1F*)(h->Clone());
  h1->SetName("Gaussian");
  
  float data1[100]={97,113,117,109,119,106,93,103,118,119,108,107,117,104,110,112,119,108,106,95,98,111,109,121,116,125,116,119, +
  130,115,101,114,109,119,114,103,98,102,115,128,115,126,114,102,136,118,132,121,104,129,108,107,126,110,108,124,136,114,112,130, +
  117,116,117,124,101,131,124,113,104,104,112,112,110,124,105,112,102,105,137,103,132,135,129,119,94,128,113,110,119, + 
  110,107,107,120,135,116,91,136,127,98,117};
 
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