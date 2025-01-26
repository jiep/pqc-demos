# Hybrid signature scheme
# Ed448 + ML-DSA-87

import oqs
from cryptography.hazmat.primitives.asymmetric.ed448 import Ed448PrivateKey

message = "An important message to sign"
message = message.encode()

PQC_SIGNATURE_SCHEME = "ML-DSA-87"

print("[KEYGEN] Generating keypairs...")
signer = oqs.Signature(PQC_SIGNATURE_SCHEME)
        
# Generate keypair for ML-DSA-87
print("[KEYGEN] Generating keyapir for ML-DSA-87...")
pkPQC = signer.generate_keypair()
skPQC = signer.export_secret_key()
print(f"[KEYGEN] pkPQC ({len(pkPQC)} bytes): {pkPQC.hex()[:32]}...{pkPQC.hex()[-32:]}")
print(f"[KEYGEN] skPQC ({len(skPQC)} bytes): {skPQC.hex()[:32]}...{skPQC.hex()[-32:]}")

# Generate keypair for Ed448
print("[KEYGEN] Generating keyapir for Ed448...")
skT = Ed448PrivateKey.generate()
pkT = skT.public_key()
print(f"[KEYGEN] pkT ({len(pkT.public_bytes_raw())} bytes): {pkT.public_bytes_raw().hex()}")
print(f"[KEYGEN] skT ({len(skT.private_bytes_raw())} bytes): {skT.private_bytes_raw().hex()}")

# Sign message with both signature schemes
print(f"\n[SIGN] Signing message \"{message.decode()}\" with both signature schemes...")

# Sign message with ML-DSA-87
print(f"[SIGN] Signing message \"{message.decode()}\" with ML-DSA-87...")
signaturePQC = signer.sign(message)
print(f"[SIGN] sigPQC ({len(signaturePQC)} bytes): {signaturePQC.hex()[:32]}...{signaturePQC.hex()[-32:]}")

# Sign message with Ed448
print(f"[SIGN] Signing message \"{message.decode()}\" with Ed448...")
signatureT = skT.sign(message)
print(f"[SIGN] sigT ({len(signatureT)} bytes): {signatureT.hex()[:32]}...{signatureT.hex()[-32:]}")
print("[SIGN] Hybrid signature is sigPQC || sigT")

# Verify signatures. The hybrid signature is valid
# if and only if both signatures are valid.
print("\n[VERIFY] Verifying signatures...")
print("[VERIFY] The hybrid signature is valid")
print("[VERIFY] if and only if both signatures are valid")

# Check signature with ML-DSA-87
print("[VERIFY] Verifying signature with ML-DSA-87...")
verifier = oqs.Signature(PQC_SIGNATURE_SCHEME)
isValidPQC = verifier.verify(message, signaturePQC, pkPQC)
print(f"[VERIFY] Is signature valid for ML-DSA-87?: {isValidPQC}")

# Check signature with Ed448
# Raises cryptography.exceptions.InvalidSignature when the signature cannot be verified.
try:
    print("[VERIFY] Verifying signature with Ed448...")
    isValidT = True if pkT.verify(signatureT, message) is None else False
    isValidT
except:
    isValidT = False

print(f"[VERIFY] Is signature valid for Ed448?: {isValidT}")

# Hybrid signature is valid iff both signatures are valid
print("[VERIFY] Hybrid signature is valid iff both")
print("[VERIFY] signatures are valid")
isValid = isValidPQC and isValidT
print(f"[VERIFY] Is hybrid signature valid?: {isValid}")