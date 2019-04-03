
uniform sampler2DRect image;
uniform float time;
uniform vec2 mouse;


void main() {
    
    float dist = distance(gl_TexCoord[0].st, mouse);
    vec2 pos = gl_TexCoord[0].st * vec2(sin(dist*0.01 + time + gl_TexCoord[0].st.x*0.01), 1.0);
    vec3 color = texture2DRect(image, pos).rgb;

    gl_FragColor = vec4( color,1.0);

}
