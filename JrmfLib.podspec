#
#  Be sure to run `pod spec lint JrmfStandardDemo.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|


  s.name         = "JrmfLib"
  s.version      = "1.0.1"
  s.summary      = "some sources of jrmf360"
  s.homepage     = "https://github.com/VamCriss/JrmfStandardDemo.git"
  s.license      = 'MIT'
  s.author       = { "criss" => "ericluo0114@hotmail.com" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/VamCriss/JrmfStandardDemo.git", :tag => s.version }
  s.resource     = 'jrmfLib/*.{bundle,cer,framework}'
  s.requires_arc = true

  s.subspec 'AlipaySDK' do |ss|
    ss.resource     = 'jrmfLib/AlipaySDK/**'
    ss.frameworks = 'SystemConfiguration', 'CoreGraphics', 'QuartzCore', 'CoreText', 'CoreGraphics', 'UIKit', 'Foundation', 'CFNetwork', 'CoreMotion'
    ss.library = 'z', 'c++'
  end


  s.subspec 'WeChatSDK' do |ss|
    ss.frameworks = 'AVFoundation', 'Security', 'SystemConfiguration', 'CoreTelephony', 'CFNetwork'
    ss.library = 'sqlite3', 'c++', 'z'

    ss.subspec 'WXSDK' do |sss|
       sss.vendored_libraries = 'jrmfLib/WeChatSDK/WXSDK/libWeChatSDK.a'
       sss.source_files = 'jrmfLib/WeChatSDK/WXSDK/*.h'
    end

    ss.subspec 'SPaySDK' do |sss|
      sss.vendored_libraries = 'jrmfLib/WeChatSDK/SPaySDK/libSPaySDK.a'
      sss.resource     = 'jrmfLib/WeChatSDK/SPaySDK/SPaySDKResource.bundle'
      sss.source_files = 'jrmfLib/WeChatSDK/SPaySDK/*.h'
    end
  end

end