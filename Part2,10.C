{
	
  gStyle->SetOptFit(1111);
  
  TF1 *f = new TF1("f", "[0]*TMath::Poisson(x,[1])", 40, 90);
  TF1 *g = new TF1("g","gaus", 40, 90);
  f.SetParameters(10, 100); 
  
  TH1F *h = new TH1F("Poisson", "Number of decay distribution (10 secs)", 20, 40, 90);
  TH1F *h1 = (TH1F*)(h->Clone());
  h1->SetName("Gaussian");
  
  float data1[100]={54,68,71,62,65,72,53,75,58,53,70,50,65,62,63,62,66,66,48,61,66,60,69,64,63,68,81,63,46,61,64,63,70,59, + 
  57,49,45,88,46,55,67,53,73,60,77,59,65,54,77,63,76,71,77,57,65,85,62,65,69,75,46,73,78,65,67,67,63,72,68,58,72,70,72,62,60,63, + 
  72,72,56,52,70,81,66,47,56,64,65,52,62,66,63,71,54,54,53,66,64,63,66,55};
 
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