double magic(double x) {
  //xの最上位bit
  int n = floor(log2(fabs(x)));
  return pow( 2.0 , n + 53 ); //丸めの影響を最大にする為、有効桁数分左にずらす
}
