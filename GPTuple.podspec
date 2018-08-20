Pod::Spec.new do |s|
s.name = 'GPTuple'
s.version = '1.0.0'
s.summary = 'GPFoundation 基础库，提供tuple功能.'
s.license = 'MIT'
s.author  = { "一凡" => "code_li_yw@163.com" }
s.homepage = 'https://github.com/YanweiLi/GPTuple'
s.source = { :git => "https://github.com/YanweiLi/GPTuple.git" , :tag => "feature_#{s.version}"}
s.platform = :ios, "7.0"
s.ios.deployment_target = "7.0"
s.vendored_frameworks = '*.framework'
s.requires_arc = true
end