{

  gStyle->SetOptFit(1111);
  
  TF1 *f = new TF1("f", "[0]*TMath::Poisson(x,[1])", 0, 20);
  TF1 *g = new TF1("g","gaus",0,20);
  f.SetParameters(2, 10); 
  
  TH1F *h = new TH1F("Poisson", "Number of decay distribution (1 sec)", 20, 0, 20);
  TH1F *h1 = (TH1F*)(h->Clone());
  h1->SetName("Gaussian"); 
  
  float data1[100]={15,12,7,13,12,14,12,10,12,6,9,12,12,12,8,9,12,15,9,14,13,16,10,13,11,12,16,7,7,20, + 
  15,6,7,9,12,10,12,16,17,13,18,13,15,12,8,9,13,9,9,12,8,15,14,14,18,15,5,12,10,11,12,15,9,4,10,13,13,10,16,14,12,7,12,13, + 
  18,8,9,9,,11,15,7,9,8,11,9,15,14,11,14,9,12,14,14,12,10,12,10,15,7,8};
 
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