function stringToSeed(str) {
      if (str === "" || str === "[random]") return "[random]";
      let hash = 0;
      for (let i = 0; i < str.length; i++) {
        const char = str.charCodeAt(i);
        hash = ((hash << 5) - hash) + char; // hash * 31 + char
        hash |= 0; // Convert to 32-bit integer
      }
      return hash;
    }

    // Validate and process seed
    function validateSeed() {
      const input = document.getElementById("seedInput").value.trim();
      let seed;

      if (input === "" || input === "[random]") {
        seed = "[random]";
      } else {
        const num = parseInt(input);
        seed = isNaN(num) ? stringToSeed(input) : num;
      }

      document.getElementById("result").textContent = 
        `Validated Seed: ${seed}`;
    }
